//RJQMISHI.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����ң�ʯ��֮��Ƕ����յ�͵ƣ�����������ʯ�ҵذ���
�������ͣ�������һ�޴���¯���ƺ�Ҳ��ذ���Ϊһ�塣¯�л������ܣ�
���׳��졣����׳ʿ���ڴ���ʲô���������ϵĴ��������Ǵ����ﴫ��
�ġ�ʯ�ҽ�������һ��С����(men).
LONG );
	set("exits", ([
		"south" : __DIR__"rjqjiguan",
		"down"  : __DIR__"rjqmenlou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 860);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}