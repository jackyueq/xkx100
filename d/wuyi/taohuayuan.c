// Room: /d/wuyi/taoyuan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�һ�Դ");
	set("long", @LONG
����ʯ�ţ���Ȼ���ʣ��������ѷǳ����ͣ�����������Դ�ˡ���ֻ
������Ⱥ�ͻ��ƣ����ƽ������İ�ݺᣬ����ٲȻ���һ�ʢ����������
ϼ������ߴ���Դԣ�����ҡҷ��������ʤ���δ���ʯ�á����������
�˱������ӡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"taoyuandong",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4970);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

