// Room: /d/nanshaolin/banruo2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�����ö���");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�
���ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ��
�����׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������е�
�ط������پ����书�����ڴ������
LONG );
	set("exits", ([
		"south" : __DIR__"banruo1",
		"north" : __DIR__"banruo3",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanen" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

