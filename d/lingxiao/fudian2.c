// Room: /d/lingxiao/fudian2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�����������ǵĸ���֮һ������������������һ����ͷ���Եز�
֪�ڸ�ʲô���������ģ�׼ûʲô���¡�����������ﲻ̫ƽ���鷳
����Ҳͦ��ģ���������Ϊ�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"lianwu2",
		"west" : __DIR__"dadian",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
	]));
	set("coor/x", -30990);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

