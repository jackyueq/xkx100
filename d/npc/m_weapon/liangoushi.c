// ROOM lianbianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ŷ��Ĵ���ֹ��ĵط����Ͻ���Ƨ��ɽ�����ܣ�������
������Ĺ�ľ�ԣ���һ�۴�ʯ�ݳɵ�Ҥ����ʯͷ���˿ڴ�����յ���
�������ڳ�ʪ������ˮ������������ȴ��ˬ�������������ˡ�һ��С��
��������ؿ��ڶ��ڣ����ֽ��������ǰ��������˸���β�Ͳݣ���Ц
��Ц�ؿ����㡣
LONG  );
	set("exits", ([
		"east" : "/d/wudujiao/wdsl3",
	]));
	set("objects",([
		__DIR__"npc/shigou" :1,
	]));
	set("coor/x", -44980);
	set("coor/y", -81060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
