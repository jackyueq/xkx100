// Room: /d/luoyang/futusi.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "��ͼ��");
	set("long",  @LONG
��ͼ����Ϊ��������֮Դͷ�����ס�Ի�����ӳ�ͼ������飬ʥ��
��֮�����ഫ������ߡ���ǧ��֮����ʱ����һ����ӻƺ�Ծ��������
���С�һ�����£����߾��ϣ����˾����ľž��ҡ�֮���֣���Ϊ��ͼ��
�������պ�ͼ������Ϊ���ԡ���˵������ǵ��ꡰ����ͼ��֮����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"dukou",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -480);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
