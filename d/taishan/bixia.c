// Room: /d/taishan/bixia.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ϼ��");
	set("long", @LONG
����һ����ʷ�ƾö���ΰ׳������Ժ���ഫ�������ƴ���ǰ���Ρ�
Ԫ�����������������������Ժ���ж�������ֱ��Ϊ�������⣬��
���Ž���͵ľ�ʩ����������߶����������ɡ����ķ�������̩ɽ����
����Ů�������ȵ���ϼ����Ȼ��ŵ�����������������������߱��
���ﱦ���롣
LONG );
	set("exits", ([
		"west"      : __DIR__"yunuchi",
		"westup"    : __DIR__"weiping",
		"southeast" : __DIR__"baozang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
