// Room: /d/yueyang/xiangchunting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "�㴻ͤ");
	set("long", @LONG
��¯ɽ�ϣ��е���ʯ���������ɶ�ʯͤ����Ի�㴻ͤ��ǰ����ʯ��
��¯һ����ͤ¯��Ӧ��������ᡣɽ������Ȼ�ıܷ�ۣ��δ���ô��Ӣ
�ۺ����ڴ˽��壬����֮ʦ����ѻ��֮ս������ˮ��֮�㽫̨������
ս������ѩ������������������Ŷ��϶�׳�ۣ�������ܼ����١�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"xianglushan",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/fang" : 1,
	]));
	set("coor/x", -1800);
	set("coor/y", 2250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
