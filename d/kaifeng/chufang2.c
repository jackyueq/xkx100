// /kaifeng/chufang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��ի��");
	set("long", @LONG
��ի���ļ��������յ���������ɫ���������Ҷ�����һ�����ż��
�����ɲ񣬺����Ǻ����ޣ�˵�������ֲ������ķ��˲�ȥ����һ��
�����ϰ���һ����Ͱ�������и�С�ų�ȥ��
LONG);
	set("objects", ([
		__DIR__"npc/suzhai" : 1,
		__DIR__"npc/shaohuo" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"chufang",
		"east" : __DIR__"zoulang1",
	]));

	setup();
	replace_program(ROOM);
}
