// Room: /d/tiezhang/zzfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��ָ��");
	set("long", @LONG
�����������ɽ����߷塪����ָ�塣����ɽ��̫�ߣ��嶥�Դ���
�����Ļ�ѩ����ѩ������������������£�����һƬҫ�۵����⡣��Ŀ
Զ�������������ﾰɫ�����۵ף���Ϫ����Ϫ�������������ɽ�»���
������Զ��������ɫ�����ߣ����������Ĵ󽭡����佭��
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1770);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
