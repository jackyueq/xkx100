//Edited by fandog, 02/15/2000

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵���򣬳���Զ�ε������������������ǳ����֡���ʱ������
����������߷ɳ۶���������һ·���������ϵ��˸������ž�װ����
���������еĻ���������ŵ�������������Щϰ��Ľ����ˡ���·����
����������������֡�����ϸ������Լ���Ըо��󽭵ı�����������
��ľ�š�
LONG );
	set("exits", ([
		"south" : __DIR__"yidao",
		"north" : __DIR__"dangyangqiao",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}