//Edited by fandog, 02/15/2000

inherit ROOM;
void create()
{
	set("short", "ҩ�ĵ�");
	set("long", @LONG
����һ��ҩ�ĵ꣬�߽������ŵ��̱ǵ�ҩζ����ҩ���ϼ��ٸ�С��
����ű����д��ҩ���ͼ۸�ҩ���ƹ����ڲ輸�ԣ����Ժ��Ų裬��
Ҳ������һ�ۡ�һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ�
�ƵĹ��(guanggao)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
����  ��֥  ����  ���  ����\n"
	]));
	set("objects", ([
		__DIR__"npc/boss1" : 1,
		__DIR__"npc/huoji1" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"hzjie4",
	]));
	set("coor/x", -1510);
	set("coor/y", -2130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}