//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
����֪�����˽Ӵ����͵ĵط������Ų輸���Σ�ǽ�ϻ����˼���ɽ
ˮ�������輸�������һ����������ð��������
LONG);
	set("exits", ([
		"north" : __DIR__"huapu",
		"east"  : __DIR__"shanfang",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1488);
	set("coor/y", -2031);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}