// Room: /qingcheng/songfengguan.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�������ɷ��������г����ݻ����Լ�����ɲ������ơ����е�
��������Ҳ�ܵü�Ϊ���£���΢�������������ϡ�������ڹ��ż�����
����һЩ����ɶ��ű������������Ǳ���ǰ�������ǵ���ն����ħʱ��
������������ڴ˼���������ӡ�
LONG );
        set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"caochang",
		"north" : __DIR__"garden",
	]));
	set("objects", ([
		__DIR__"npc/hou" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -830);
	set("coor/z", 90);
	setup();
	"/clone/board/qingcheng_b"->foo();
        replace_program(ROOM);
}