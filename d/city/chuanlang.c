// Room: /yangzhou/chuanlang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����Ժ�������м���ɽʯ��ɽ��Ϊ���ң�ɽǰ�г�ˮ����ˮ��ȥ��
��һ����������ĸо�����ˮ��Ī�ɲ⣬żȻ�������Σ�ٿ����û����
���ϵ���һЩ�����ӣ����Ÿ�ɫ���񡣴��ȵ����ڣ�Ƕ�С���³������
����������У���������ת��ֻ����ͷ���������Զ÷��������
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"south" : __DIR__"menting",
		"north" : __DIR__"meichuanxuan",
	]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -11);
	set("coor/y", -49);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}