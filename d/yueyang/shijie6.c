// Room: /d/yueyang/shijie6.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
���Ǿ���ͤ����ʯ�ף��������ϣ��������¡������Ǿ���ͤ������
�£����������������µĸߴ�����һ��ʯ̨��ÿ���ؤ���ɽ��ᣬ��
������̨�Ͼ��С�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"jiuxiangting",
		"westup" : __DIR__"xuanyuantai",
	]));
	set("coor/x", -1780);
	set("coor/y", 2270);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
