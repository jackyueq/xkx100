// Room: /d/lingxiao/iceroad1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
������һƬ�������������硣����·�ϣ���ͷһ����·����������
�����ĺ������ƣ���Ө��͸�����ӳ�����˵���������ı��ϣ�Ӧ��
���ﲻ��������ϸһ����ÿ�������ϣ�������ϸϸ�Ļ��ƣ�����������
ϸ����Ȼ�ķ��˴���������
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"gate",
		"north" : __DIR__"iceroad2",
		"west"  : __DIR__"hotel",
		"east"  : __DIR__"sell",
	]));
	set("objects",([
		__DIR__"npc/li" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

