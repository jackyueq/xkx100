inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "��ˮ��");
        set("long",  @LONG
������ˮʯ�ź��Խ�ˮ���ϣ��м���������ר���ʵ�ʹ�õģ�
��Ϊ����·�ţ����ŵ���ͷȫΪ���Σ��˳ƣ��������������Ϊ��
���ţ��ŵ���ͷ��ɣ��ɻ������������ǽ�ˮ�ӻ�������ˮ��ˮ��
��ȥ���壬��˵���������������� (out)�������ǽ��ʹ����ŵı�
��֮·��
LONG);
        set("outdoors", "beijing");
        set("exits", ([
                "north" : __DIR__"zhengmen",
                "south" : __DIR__"tian_anm",
                "west" : __DIR__"bridge2",
                "east" : __DIR__"bridge3",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_out", "out");
}

int do_out(string arg)
{
	object me;
	int i, ging_cost, qi_cost;

	me = this_player();
	i = (int)me->query_skill("dodge", 1) + random(50);
	ging_cost = 300 / (int)me->query("int");
	qi_cost = 300 / (int)me->query("int");
	if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
		i = 0;

	message_vision("$N����ʯ����һ������������ȥ��\n", me);
	if ( i < 75)
		{
	        message_vision("һ��Ǳ�����̰�$N��û�ˡ�\n", me);
		me->die();
	        }
	else if( i < 100)
		{
	        message_vision("һ��Ǳ�����̰�$N��û�ˡ�\n", me);
		me->unconcious();
		switch( random(2) ) {
		case 0:
		me->move(__DIR__"bridge2");
			break;
		case 1:
		me->move(__DIR__"bridge3");
			break;
		message_vision("һ��Ǳ����$N��ذ��ߡ�\n", me);
		}
	        }
	else {
		switch( random(5) ) {
		case 0:
		message_vision("һ��Ǳ����$N��ذ��ߡ�\n", me);
		me->move(__DIR__"bridge2");
			break;
		case 1:
		message_vision("һ��Ǳ����$N��ذ��ߡ�\n", me);
		me->move(__DIR__"bridge3");
			break;
		case 2:
		case 3:
		case 4:
		message_vision("$N��ˮ�л������غ���������ͻȻ֮�䴥����һ��Ӳ�ڡ�\n", me);
		message_vision("$N����ץס�˾������ݣ����Ż������Ӳ�ھ͸�����ˮ�档\n", me);
		message_vision("$N����һ��ˮ��̧ͷһ����ԭ������һ�ھ��С�\n", me);
         	me->move("/d/huanggong/inwell");
		break;
		}
		if( (i > 125) && me->query_skill("dodge",1)<101)
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
	     }
	return 1;
}
