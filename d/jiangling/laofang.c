//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{

	set ("short", "�η�");
	set ("long", @LONG
����ԼĪ���ɼ�����һ���ʯ�ݣ�ǽ�ڶ���һ���ֲڵĴ�ʯ������
����Ҳ�Ǵ�ʯ���̳ɣ�ǽ���������һֻ��Ͱ�������ŵ��ľ��ǳ�����
ù�����η���ȴ������������ૣ������ﴦ��ȥ��ֻ��һ�����ӽ��ɽ�
Զ������ʮ�����¥�ϵĴ����ӹ�����ɴ�������ع��ţ�������ȴ����
����һ���ʻ�������������õ�壬�����Ƕ��㡢���ɡ�
LONG);
	set("exits", ([ 
		"west" : __DIR__"yongdao",
	]));
	set("objects", ([
		__DIR__"npc/ding" : 1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -1450);
	set("coor/y", -2029);
	set("coor/z", 0);
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}
