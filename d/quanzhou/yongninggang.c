// Room: /d/quanzhou/yongninggang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������Ȫ������ۿ�֮һ���������ˮ���ƽ�˾�����ĿԶ����
����һɫ��ε����Ͼ������ͣ������������ĸ��ִ�ֻ���ϱߵĹ�ɩ��
������һ�����˵Ĺ��¡�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"       : __DIR__"gushaota",
		"northwest"   : __DIR__"portroad4",
	]));
	set("objects", ([
		__DIR__"npc/kuli" : 1,
		"/d/taishan/npc/tiao-fu" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6630);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
