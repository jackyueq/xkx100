//Edited by fandog, 02/15/2000

inherit ROOM;
void create ()
{

	set ("short", "����");
	set ("long", @LONG
�����ǽ���֪�������Ŵ��á������ǡ��ྲ�������رܡ������ӣ�
ʮ����������ˢˢ��վ�ţ�����ˮ��������ӵ����ġ�֪���������ڰ�
̨������ر������㡣�����Ϸ���һ���ң���д�������������ĸ���
�֡�һ��ʦү������վ��֪��������󣬲�ʱ����Դ��˶��Ｘ�䡣
LONG);

	set("exits", ([ 
		"east" : __DIR__"huapu",
		"west" : __DIR__"yamen",
	]));
	set("objects", ([
		"/d/city/npc/yayi" : 4,
		__DIR__"npc/shiye" : 1,
		__DIR__"npc/ling"  : 1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -1489);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}