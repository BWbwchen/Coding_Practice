# Partition too full

One day, when I upgrade my system with pacman on manjaro.
It tell me this :

	error: Partition / too full: 127836 blocks needed, 95781 blocks free
	error: failed to commit transaction (not enough free disk space)
	Errors occurred, no packages were upgraded.

Ooops , so after google a little, I realize it could be my `cache file` problem.

Pacman will store all downloaded packages in `/var/cache/pacman/pkg/`

So let check how much cache file I have !

```
$ sudo ls /var/cache/pacman/pkg/ | wc -l
1024
```

`wc` stand for `word count`. `-l` will print the mewline counts.

So I have `1024` cached packages, lets count how much disk space used by cached file.

```
$ du -sh /var/cache/pacman/pkg/
3.9G	/var/cache/pacman/pkg/
```

3.9G !! lets try to clean some old version file by use `paccache`

see [`archwiki_pacman`](https://wiki.archlinux.org/index.php/pacman)

It will delete all cached package except for the most recent 3 versions.

So clean it !

```
$ paccache -r
==> Privilege escalation required
[sudo] password for xxx: 

==> finished: 62 packages removed (disk space saved: 356.66 MiB)
```

clean uninstalled packages:

```
$ paccache -ruk0
==> Privilege escalation required

==> finished: 8 packages removed (disk space saved: 26.67 MiB)
```

store only the most 2 version :

```
$ paccache -rk2
==> Privilege escalation required

==> finished: 103 packages removed (disk space saved: 755.55 MiB)
``` 

Now let's see how much disk place it used :

```
$ du -sh /var/cache/pacman/pkg/
2.8G	/var/cache/pacman/pkg/
```

Ok , It seems that I have enough space to upgrade!