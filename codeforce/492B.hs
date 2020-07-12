import Data.List
import System.IO


readInput :: Read a => IO [a]
readInput = fmap (map read . words) getLine 

getNLine :: Int -> IO [String]
getNLine n
    | n <= 0 = return []
    | otherwise = do
        x <- getLine
        xs <- getNLine $ n-1
        let ret = (x:xs)
        return ret

main :: IO ()
main = do
    n <- readInput :: IO [Int]
    l <- readInput :: IO [Int]
    let xs = reverse (last n : reverse (0 : sort l))
    let dis = zipWith (-) (tail xs)  xs 
    -- print dis
    print $ solve dis
    -- putStrLn xs 
    

solve :: [Int] -> Double
solve li =  max max_dis end_point
    where
        max_dis = fromIntegral (maximum li) / 2
        end_point = fromIntegral (max (head li) (last li)) 
