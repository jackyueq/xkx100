// Room: /d/tiezhang/shishi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ɽ������ɵ�Сʯ�ݣ��м���һ��ʯ�������ϰڷ���һ
յ�͵ƣ�ɢ����������ƵĹ���������һ�ǵĵ��ϣ����źܶ�ɲݣ���
������һ���ˡ��������£���ȥ���ݣ������������ͣ����ϴ���һ��
�������Ƶĺ��£�˵�����Ĺ������ء�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"eastup" : __DIR__"shijie3",
	]));
	set("objects", ([
		CLASS_D("tiezhang")+"/shangguan" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -2050);
	set("coor/y", 1870);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
