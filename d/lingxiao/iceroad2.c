// Room: /d/lingxiao/iceroad2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�����������ǵ��Ͻ֣������ǵĵ��ӡ����ˡ����������Ծ�ס�ڳ�
��������Դ�������һ�����꣬����������Ǳ�ѧ��ң֮ʿ��������
֮��ͥΪ�������˼�֮��������ߴ�֮�庮�������������ӾӴ�������
Ƨ֮�أ�����������Ϣ����������������������һ�ҵ����̣�������һ
��ҩ�̡�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"iceroad1",
		"north" : __DIR__"iceroad3",
		"west"  : __DIR__"wuqi",
		"east"  : __DIR__"yaodian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

