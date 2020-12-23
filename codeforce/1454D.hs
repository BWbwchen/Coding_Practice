import Data.Foldable
import Data.List
 
main = do
  cas <- read <$> getLine
  --mapM_ solveOneCase [1 .. cas]
  mapM_ solveOne [1 .. cas]
 
--solveOneCase _ = getLine >> getLine >>= print . solve . map read . words
-- solveOne _ = getLine >>= print . solve . read 
-- <- for action
-- let = for result
solveOne _ = do 
                n <- read <$> getLine
                let ans = solve n
                print $ length ans
                putStrLn $ myshow ans


myshow xs = unwords $ map show xs

solve :: Integer -> [Integer]
--solve a = decompose a
solve x = ansList
    where decomposeList = sortBy compareFunc $ decompose 2 x
          (elementNum, element) = head decomposeList
          pendingList = replicate (fromInteger (elementNum - 1)) element
          ansList = pendingList ++ remainList
          remainList = [foldl (\x (y, yn) -> x * (yn^y)) element $ tail decomposeList]
          

--decompose :: Int -> [(Int, Int)]
decompose :: Integer -> Integer -> [(Integer, Integer)]
decompose p x 
    | x == 0 = []
    | x == 1 = []
    | p * p > x = [(1, x)]
    | rem x p == 0 = (appearTime, p) : decompose (p+1) (div x (p^appearTime))
    | otherwise = decompose (p+1) x
    where appearTime = g x p 0

g :: Integer -> Integer -> Integer -> Integer
g x p cummu
    | rem x p == 0 = g (div x p) p (cummu+1)
    | rem x p /= 0 = cummu


compareFunc :: (Integer, Integer) -> (Integer, Integer) -> Ordering
compareFunc (a, an) (b, bn)
    | a < b = GT
    | a > b = LT
    | otherwise = EQ
