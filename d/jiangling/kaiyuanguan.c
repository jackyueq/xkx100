//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��Ԫ��");
	set ("long", @LONG
����һ�������Ĺŵ��ۣ�Զ��ɽ�ţ���Լ�ɼ����ڼ���������ܴ�
�䣬�ۻ�׳�ۡ������ıڿ�������ī�͵���ʣ��ڷŵ��ӡ�¯�������
�ȣ��޲����ⰻȻ��
LONG);
	set("exits", ([ 
                "east"  : __DIR__"xijie4",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}