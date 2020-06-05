import Data.List
import System.IO

-- sqrt using binary search
-- usage mySqrt 7 0 7
-- output : 2
mySqrt :: Int -> Int -> Int -> Int
mySqrt x l r
    | l > r = r
    | mid^2 < x = mySqrt x (mid+1) r
    | x < mid^2 = mySqrt x l (mid-1)
    | x == mid^2 = mid
    | otherwise = -1
    where mid = floor $ (fromIntegral l + fromIntegral r)/2

-- Find the first 1
-- x eg: [0, 0, 0, 0, 1, 1, 1, 1] 
-- usage search [0, 0, 0, 0, 1, 1, 1, 1] 0 7
-- output : 4
search :: [Int] -> Int -> Int -> Int
search x l r
    | l > r = l
    | x!!mid == 1 = search x l (mid-1)
    | x!!mid == 0 = search x (mid+1) r 
    where mid = floor $ (fromIntegral l + fromIntegral r)/2

-- Find the peak
-- x eg: [0, 0, 0, 0, 1, 1, 1, 1] 
-- usage findPeak [1, 2, 3, 1] 0 3
-- output : 3(peak number)
findPeak :: [Int] -> Int -> Int -> Int
findPeak xs l r
    | l > r = xs!!r
    | x!!mid == 0 = findPeak xs l (mid-1)
    | x!!mid == 1 = findPeak xs (mid+1) r 
    where mid = floor $ (fromIntegral l + fromIntegral r)/2
          x = 1 : zipWith (\a b -> if xs!!a - xs!!b < 0 then 1 else 0) [0..length xs - 1] [1..length xs - 1]
