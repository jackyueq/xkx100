// ROOM liandaoshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ŷ������������Ĵ������˽�������ζ�����ȵ����˳�
���˲��ɴ��˸�����һ��Ƥ����ڵ�С��������һ��ʯͷ����Ϣ����
��һ���޴�Ĵ�ͷ����ͣ�����ذڶ��š�������С���Ҫ˯���ˡ�
LONG );
	set("exits", ([
		"south" : "/d/xingxiu/tianroad5",
	]));
	set("objects", ([
		__DIR__"npc/shidao" :1,
	]));
	set("coor/x", -52010);
	set("coor/y", 20150);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
