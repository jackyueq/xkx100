// Room: /yangzhou/shuyuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ͥԺ");
	set("long",@LONG
�������׶���Ϊ��Ժ���ã���������ֹ����������տ�����⡣԰��
������ľ�����һ�����ɻ��񣬼��Ի��ܣ�����ʯ��ɽ����˳����Ȼ��
����Ժ�ڡ���ĿѰ��������Զ����
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"south"   : __DIR__"qionghuajie",
		"northup" : __DIR__"shuyuan1",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 31);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}