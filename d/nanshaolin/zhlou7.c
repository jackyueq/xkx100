// Room: /d/nanshaolin/zhlou7.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥�߲�");
	set("long", @LONG
���������¥֮����ֱ�������ı����ǿڴ��Ӻ�һ�����ҿ��еľ�
�ơ�ϸ�����ӣ��������������ߣ�ֱ��Ҳ����������������ͭ������
�����������������ӡ�Ĺ�׭������������ǧ����ƴֿɺϱ����ɰ�
������һͷ���Ժ�Ƥ��������������
LONG );
	set("exits", ([
		"down" : __DIR__"zhlou6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

