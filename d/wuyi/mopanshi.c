// Room: /d/wuyi/mopanshi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "ĥ��ʯ");
	set("long", @LONG
ĥ��ʯ�ڰ���֮�ϡ�������Բ��ͦ�εľ�ʯ������һ��״��һ��
ĥ�̡�����ˮ��ˢ���γɵ�һ������׵Ľ�Һ��ĥ�̵������ѷ�������
�������ʣ����ж����С��γ����ʫԻ�����ɼҺ���Ҳ������ʯ������
��ˮ����Ӧ����������ʯ����֥ǧĶ���вء���
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"8qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1330);
	set("coor/y", -5030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

