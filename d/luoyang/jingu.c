// Room: /d/luoyang/jingu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "��ȴ���");
	set("long",  @LONG
������ǵ����ȶ��ڵĽ��԰���������޸�ʯ��ı�����������
�����������������������˽�ȱ��������ơ����԰�����������£�
�����ů��ʱ���һ����ơ���˿������¥��ͤ��������ӳ��������Ծ
�����ڻ��䣻С����ౣ�����֦ͷ��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"tongtuo",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
