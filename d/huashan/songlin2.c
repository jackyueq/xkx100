// Room: /d/huashan/songlin2.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{	
	int dir1,dir2,dir3,dir4;
	dir1=random(4)+1;
	dir2=random(4)+1;
	dir3=random(4)+1;
	dir4=random(4)+1;
	while (dir1!=3 && dir2!=3 && dir3!=3 && dir4!=3)	
	{	
		dir1=random(4)+1;
		dir2=random(4)+1;
		dir3=random(4)+1;		
		dir4=random(4)+1;		
	}
	set("short", "������");
	set("long", @LONG
����һƬ�����֡����ɸߵ������������飬�ڵò������ա�������
�����룬�в�֪����Ұ��͵͵�ӹ�������һƬ�ž���
LONG );
	set("exits", ([
		"east"  : __DIR__"songlin"+dir1,
		"west"  : __DIR__"songlin"+dir2,
		"south" : __DIR__"songlin"+dir3,
		"north" : __DIR__"songlin"+dir4,
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 240);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
