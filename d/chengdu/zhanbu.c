// Room: /d/chengdu/zhanpu.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "ռ����");
	set("long", @LONG
�ſڹ���һ������(sign)�������Ե���Щ�տյ����ģ�Ϲ��������
��һ�ź���ķ�������������һ�Űײ����������һͲ�����õ���ǩ
�ͼ�öͭǮ������ǰ��һ�Ź��������ĵ��ӡ�
LONG	);
	set("exits", ([
		"south" : __DIR__"xijie1",
	]));
	set("item_desc",([
		 "sign": "���㲻�����㣬���㲻�����㡣\n",
	]));
	set("no_clean_up", 0);
       	set("coor/x", -8070);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

