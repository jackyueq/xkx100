// Room: /d/yueyang/longxianjing.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "���Ѿ�");
	set("long", @LONG
���Ѿ�������ɽ�£�����ľ�ˮ�峺��������ʱ���ԣ�������ͷ��
��һ�����µ���ˮ���ʳơ����Ѿ�������������ɫ��ʯ�������࣬Ȫ
ˮ����ʯ��ע�뾮�ڣ�һ��һ�Σ�������ˮ����ȥ��ˮ���겻�ԣ��峺
���ף���ů�����������ഫ�������Ѿ���ˮ�ݾ�ɽ�裬���˰ٲ��Գ���
�������ϡ���������Ϊ�棬Զ��������ȡ���������ﲻ��������ɽ���
���ƣ�������������ȸ�࣬�������ƾ�ɽɫ����������
    �ྮ������Զ������һ�Ե����������߽��ɣ��ſ��ĳߣ��������
�̡����Ѿ��������Ծ��������������֡�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south"   : __DIR__"longkou",
		"northup" : __DIR__"feilaizhong",
	]));
	set("coor/x", -1720);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
