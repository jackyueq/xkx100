// Room: /d/taishan/tanhai.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "̽��ʯ");
	set("long", @LONG
�չ۷山��һ���ɽ�����ͻ���ľ�ʯ��������ʯ������̽��ʯ��
��Լ�����࣬��ֱָ��������ʯ��������ƾ������Ұ��������������
���ߵ�ɫ���ˣ���ͨ��һ�㶼�����ʵ����̽��ʯ��ʯ���С������
����ʯ�ҡ�������ʯ�������������ȿ̡��������Ͽɾ������ն�����׳
�����棬�������ɽɫ�������ƺ���������ʫ���������켦����������
ɣ�����ѳ�������ã�������ƶ���ʯ�����˱����顣��
LONG );
	set("exits", ([
		"westdown" : __DIR__"riguan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
