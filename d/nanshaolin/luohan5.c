// Room: /d/nanshaolin/luohan5.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�޺����岿");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�
���ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ��
�����׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������е�
�ط������پ����书�����ڴ������
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc6",
		"south" : __DIR__"luohan4",
		"north" : __DIR__"luohan6",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuankong" : 1,
	]));
	set("coor/x", 1760);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

