// Room: /d/lingxiao/fudian1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�����������ǵĸ���֮һ��ѩɽ��������ӣ������Ű������⣬��
����֧����֧����Լ���ϵ����ʲô�£����ֲ����ᵽȫ�ɽ���ģ���
�����ڸ������顣
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"lianwu1",
		"east"  : __DIR__"dadian",
	]));
	set("objects", ([
	       __DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31010);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

