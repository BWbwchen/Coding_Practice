import Control.Monad -- for replicateM_

solve :: [Integer] -> [Integer] -> Integer
solve a b = answer
    where 
        min_a = minimum a
        min_b = minimum b
        substract_min_a = map (\x -> x - min_a) a
        substract_min_b = map (\x -> x - min_b) b
        answer = sum $ zipWith (\x y -> max x y) substract_min_a substract_min_b

deal :: IO()
deal = do 
    getLine
    a <- map read . words <$> getLine
    b <- map read . words <$> getLine
    putStrLn $ show $ solve a b

main :: IO()
main = getLine >>= flip replicateM_ deal . read 
