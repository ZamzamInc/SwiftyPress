//
//  AuthorsRepositoryTests.swift
//  SwiftyPress
//
//  Created by Basem Emara on 2018-06-03.
//

#if !os(watchOS)
import XCTest
import SwiftyPress

final class AuthorRepositoryTests: BaseTestCase {
    private lazy var authorRepository = core.authorRepository()
}

extension AuthorRepositoryTests {
    
    func testFetchByID() {
        // Given
        var promise: XCTestExpectation? = expectation(description: #function)
        let id = 2
        
        // When
        authorRepository.fetch(id: id) {
            // Handle double calls used for remote fetching
            // $0.value != nil else { return }
            defer { promise?.fulfill(); promise = nil }
            
            // Then
            XCTAssertNil($0.error, $0.error.debugDescription)
            XCTAssertNotNil($0.value, "response should not have been nil")
            XCTAssert($0.value?.id == id)
        }
        
        waitForExpectations(timeout: 10, handler: nil)
    }
    
    func testFetchByIDError() {
        // Given
        let promise = expectation(description: #function)
        let id = 99999
        
        // When
        authorRepository.fetch(id: id) {
            defer { promise.fulfill() }
            
            // Then
            guard case .nonExistent? = $0.error else {
                return XCTFail("response should have failed")
            }
        }
        
        waitForExpectations(timeout: 10, handler: nil)
    }
}
#endif
