// Room: /d/nanshaolin/luohan9.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�޺��þŲ�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�
���ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ��
�����׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������е�
�ط������پ����书�����ڴ������
LONG );
	set("exits", ([
		"south" : __DIR__"luohan8",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanyang" : 1,
	]));
	set("coor/x", 1760);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

