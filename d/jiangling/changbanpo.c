//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "������");
	set ("long", @LONG
����ʱ������������ս����ʷ�أ���������ʮ���꣨��Ԫ 208�꣩
�������ܲ�׷�����ˣ����ŷɵ���ʮ���������ӣ�����������ܾ�Χ��
�ڴˣ��������Ƶ�ǹƥ��������֮�Ӱ�����ԡѪ��ս���������޸�
����ͻΧ������ң�Խ���ɽ����Ϊ��ʱ�ܲٵǸ߹���֮������ɫ������
������ˡ� 
LONG);
	set("exits", ([  
		"east" : __DIR__"dangyangqiao",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
