//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����֪�����ŵ��ŷ���һλ������վ����̨����Ц���еؿ����㣬
����������һ�����ף������ذѹ������ŵ�һ���ʳ����ȡ�����һ��
�����������ϵ���������롣
LONG
	);
	set("exits", ([
		"west" : __DIR__"keting",
	]));
	set("objects", ([ 
		__DIR__"npc/chuniang" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -1387);
	set("coor/y", -2031);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}