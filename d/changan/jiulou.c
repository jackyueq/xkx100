// /d/changan/jiulou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "����¥");
	set  ("long",  @LONG
���������������������¥��������̫�����������ɵĵط�������
����߽�ȥ���Ϳ���һ�����ӣ��ݲ�Ӫҵ�����˽�֪���������ƣ�����
�ھƣ������ܾơ���õķھƲ���ɽ���������������������¥���㣬
ԭ�����Ǵӵؽ���Ʈ�����ġ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"down"  :  __DIR__"dijiao",
		"west"  :  __DIR__"northroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -5030);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
