// Room: /d/suzhou/road6.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "���ϴ��");
        set("long", @LONG
������һ����ʯ����ϣ�����ң��������ɽչ���������ǰ������
������ң��̫����ɫ���̲���ɭ��������ǧ������̫��֮�ϣ����ֵ��䣬
ǧ��һ�ڣ���Ӱ��������ͷ������Ⱥɽ��ȥ�����측ˮ����ãˮ�棬��
��ǧ�ţ������к���ˮ����ӡ������ϰ����ϼ����ʱ�������������
�����Ŀ�������
LONG);
	set("outdoors", "suzhou");
	set("exits",([
		"north" : __DIR__"road7",
		"south" : __DIR__"road5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

