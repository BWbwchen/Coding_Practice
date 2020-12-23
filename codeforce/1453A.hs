import Data.Foldable
import Data.List
 
main = do
  cas <- read <$> getLine
  --mapM_ solveOneCase [1 .. cas]
  mapM_ solveOne [1 .. cas]
 
--solveOneCase _ = getLine >> getLine >>= print . solve . map read . words
-- solveOne _ = getLine >>= print . solve . read 
solveOne _ = do getLine
                left <- map read . words <$> getLine
                right <- map read . words <$> getLine
                print $ solve left right

solve :: [Int] -> [Int] -> Int
solve as bs = length listInteract
    where listInteract = intersect as bs

{--
import Control.Monad -- for replicateM_
import Data.List -- for sort
 
solve :: Int -> [Int]
solve n = tail $ [1..n] ++ [1]
 
listToString = unwords . map show 
 
deal :: IO()
deal = do 
    a <- readLn
    putStrLn $ listToString $ solve a
 
main :: IO()
main = getLine >>= flip replicateM_ deal . read 
--}
