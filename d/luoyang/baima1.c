// Room: /d/luoyang/baima1.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "��������");
	set("long",  @LONG
�����ǰ����µ���¥��ÿ���°׷���֮ҹ�����س�¶֮ʱ�����ڻ�
��ײ�ӷ��У���������Ʈ����Զ�������֮ʹ���Ŀ���������������
�����пڴ����ӣ���Լ��ǧ�������ر�������ݴ��������������
�����¥�ϵ�һ��������һ�£����Թ�����������������������������
��ͬʱ����������������¥�ϵ���Ҳ���ˣ���������š�����ײ������
�죬����ײ�Ӷ��������ļѻ���
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"baimasi",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
