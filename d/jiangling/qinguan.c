//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "�ٹ�");
	set ("long", @LONG
����һ�����ܸ��ʡ�����������ͤ�ӣ��Ҷ����⡰��ɽ��ˮ���ĸ�
���֡�ͤ����һ�ֻ�(zihua)��
LONG);
	set("item_desc", ([
		"zihua" : "������ϻ����ǲ�����ˤ��л֪�����Ĺ��¡����л������ľ�ʫ��
                    ˤ�����ٷ�β��
                    ���ڲ��ڶ�˭��
                    �������������
                    ����֪��������\n"
	]));
	set("exits", ([
		"south" : __DIR__"qintai",
	]));
  
	set("coor/x", -1490);
	set("coor/y", -2110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
