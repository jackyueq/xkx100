// Room: /d/yueyang/xiangfeici1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ڶ���Ĺ�Ķ����࣬�����ٶ�ͥ����Զӳ�������ɽ��
���Բ��ɴ��Ϊ����С���߸��棬�ض����ӡ��׵�Ժǽ����ɫ�����棬
����ɽң���Ӧ����ǽ��������������ӳ��г�������Ϸ�������������
������������������ɫ���֣����ڱ��Ǻ����ܶ���֮��׫д���İ��ֵ�
���µ�һ��������ĺ�ǽ�ϣ�Ϊ����ɽͼ���������̲�ˮ���ľ�ɽ��ʫ
��������ˣ������������������˴�������ظ���ԭӽ�����ճ�մ�󡣡�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"xiaolu6",
		"north" : __DIR__"xiangfeici2",
	]));
	set("coor/x", -1660);
	set("coor/y", 2310);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
