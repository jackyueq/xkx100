// Room: /d/luoyang/luoshenmiao.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "������");
	set("long",  @LONG
���񻰴�˵�У����Ӻ��������������ס����ģ�Ʃ���ĺ��е���
���ֵ��ǡ���˵���ƹ����ˮӡ�ġ�������λ��Ů����ǰ�����Ƕ���
Ϊ���Ƿ����ϵ�Ů���������������������������񣬿�������ӿ����
ͷ�ı��ǲ��ӽ������ְɡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northeast" : __DIR__"southroad",
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
