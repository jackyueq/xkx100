// Room: /d/luoyang/huadian.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
����һ�ҳ��۸��ֻ��ܵĵ��̣��㱻���˵Ļ��㣬��ɵĻ�������
�����Ų�������С��ϰ���������������ҵ���ͷ��������ôһ�һ���
����ʵ���������󡣵����Ϲ��˸�����(paizi)��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  __DIR__"southroad",
		"north" :  __DIR__"eastroad",
	]));
	set("item_desc",  ([
		"paizi" : "
�ͻ����� send <���ݴ���> to <��Ҵ���> \n",
	]));
	set("objects",  ([
		__DIR__"npc/laoban" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
