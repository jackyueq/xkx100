// Room: /d/guiyun/zoulang2.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����������������������ȡ������������������ۣ�������������
���οգ���Ŀ���⣬���������˻�����������һ��ͷ���
LONG );
	set("exits",([
		"east"  : __DIR__"zoulang1",
		"west"  : __DIR__"zoulang3",
		"north" : __DIR__"kefang",
	]) );
	set("outdoors", "guiyun");
	set("objects",([
		__DIR__"npc/zhuangding2" : 1,
	]));  
	setup();
	replace_program(ROOM);
}
