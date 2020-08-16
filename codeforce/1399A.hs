import Control.Monad -- for replicateM_

sort :: Ord a => [a] -> [a]
sort []     = []
sort (p:xs) = (sort lesser) ++ [p] ++ (sort greater)
    where
        lesser  = filter (< p) xs
        greater = filter (>= p) xs

solve :: [Int] -> Bool
solve (x:xs)
    | null xs = True
    | otherwise =  continuous && solve xs 
    where 
        continuous = abs (x - (head xs)) <= 1

formatOutput :: String -> String -> Bool -> String
formatOutput true false boolean
    | boolean == True = true
    | otherwise = false

deal :: IO()
deal = do 
    getLine
    x <- map read . words <$> getLine
    putStrLn $ formatOutput "YES" "NO" $ solve $ sort x

main :: IO()
main = getLine >>= flip replicateM_ deal . read 
