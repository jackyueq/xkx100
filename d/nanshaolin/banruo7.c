// Room: /d/nanshaolin/banruo7.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�������߲�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�
���ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ��
�����׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������е�
�ط������پ����书�����ڴ������
LONG );
	set("exits", ([
		"south" : __DIR__"banruo6",
		"north" : __DIR__"banruo8",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanwang" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

