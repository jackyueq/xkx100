// /d/city/zhonglieci.c  ������
//modified by sega 1/10/99
//�޸�a_timeΪ120,�����newjob��һЩ��Ϣ,�Է�һЩ��һֱflood
//�޸�a_timeΪ300��һЩ����ҽ��������ӳ����ʱ�䡣
//�޸���2�α��ڼ��Ϊ5����
#include <ansi.h>
#define A_TIME 300 
inherit ROOM;
// ���е�ַ���ڷ��������outdoors 
string * add_msg = ({
	"/d/city/siqiaoyanyu",		// ��������
	"/d/beijing/wangfu1",		// ���������
	"/d/chengdu/wangjianglou1",	// ����¥
	"/d/suzhou/canlangting",	// ����ͤ
	"/d/hangzhou/liulangqiao",	// ������
	"/d/fuzhou/yongquan",		// ӿȪ��
	"/d/jiaxing/yanyu",		// ����¥
	"/d/xiangyang/juyilang",	// ˮ������
	"/d/lingzhou/luorilin1",	// ������
	"/d/dali/feilihu",		// ��������
	"/d/mobei/hill",		// С��ɽ
	"/d/village/wexit",		// �����
	"/d/jiangling/chenglingji",	// �����
//	"/d/shaolin/qyping",		// ����ƺ
	"/d/wudang/haohanpo",		// �ú���
	"/d/emei/duguangtai",		// �ù�̨
	"/d/qingcheng/huyingting",	// ��Ӧͤ
	"/d/kunlun/pingfeng",		// ʯ����
	"/d/qilian/zibaipo",		// �ϰ���
	"/d/songshan/tieliang",		// ����Ͽ
	"/d/taishan/tanhai",		// ̽��ʯ
	"/d/huashan/ziqitai",		// ����̨
	"/d/henshan/liuyunping",	// ����ƺ
	"/d/hengshan/tongyuangu",	// ͨԪ��
	"/d/mingjiao/shanlu3",		// ������
	"/d/heimuya/xingxingtan",	// ����̲
	"/d/xuedao/wangyougu",		// ���ǹ�
	"/d/gumu/taiyi1",		// ̫�ҳ�
	"/d/jueqinggu/duanchangya",	// �ϳ���
//	"/d/taohua/xiuxishi",		// �һ���
//	"/d/baituo/zhuyuan",		// ��԰
//	"/d/shenlong/caoping",		// ��ƺ
	"/d/xiaoyao/qingcaop",		// ���ƺ
	"/d/xiaoyao/pubu",		// ����ٲ�
	"/d/lingxiao/sroad4",		// ��紨
//	"/d/lingjiu/daban",		// ׺����
//	"/d/xingxiu/yueerquan",		// �¶�Ȫ
	"/d/xueshan/shenghu",		// ʥ��
	"/d/wudujiao/taohua",		// �һ���
	"/d/wuliang/jianhugate",	// ��������
	"/d/tianlongsi/yaotai",		// �嶼��̨
	"/d/yanziwu/tingxiang",		// ����ˮ�
	"/d/guanwai/chuanchang",	// ����
	"/d/meizhuang/xiaoyuan",	// ����СԺ
	"/d/shiliang/tingzi",		// õ��Сͤ
	"/d/tiezhang/mzfeng",		// Ĵָ��
});

void create()
{
	set("short", "������");
	set("long", @LONG
�����������������Ǵ���¹����ΤС������ʥ�濵��ʥ����������
���ȴ�Ǵ������ұ������Ҿ���������ݶ�ʦʷ��ʷ�ɷ�����������
�ǿ������ʡ�뷽�������������������ʷ����������������ϵ���ɫ
�Ѿ��߲������ˡ����ܵĵ��ϻ���һЩ���������������Ѿ���Щʱ��û
���������ĺۼ�����ǰ�ڷ���һ�ź�ľ�߽Ź��������ϸߴ�������һ��
����(kan)��
LONG    );
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"north" : __DIR__"zizheng",
	]));

	set("count",1);
	set("item_desc", ([
		"kan" :  HIG"
������һ�Ƚϣ��㷢���������һ����Ⱦ���ɾ�����֣��������˴��Ƶġ�\n
"NOR
	]));
	set("coor/x", -30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open","dakai");
	add_action("do_open","open");

	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}

int do_open(string arg)
{
	object me = this_player();
	object ob,rz;
	string src_add,dest_add,des;
	object room,room2;

	src_add=add_msg[random(sizeof(add_msg))];
	dest_add=add_msg[random(sizeof(add_msg))];
	while (dest_add == src_add)
		dest_add=add_msg[random(sizeof(add_msg))];

	if (!arg || arg != "kan" )
		return 0;

	if (me->query_skill("dodge", 1) < 80)
		return notify_fail("����̫���ˣ�����Ṧ�����š�\n");

	if ( !wizardp(me) && time() - me->query("baobiaotime") < 300)
		return notify_fail("����ϸ���������ˣ��������ࡣЪ��ɡ�\n");

	if (query("count") > 0) {
		if (!present("mi ling",me) ) {
			if (! room = find_object(src_add) )
				room = load_object(src_add);
			rz = new(__DIR__"task2/renzhi");
			rz -> set("leader_name", me->query("id") );
			rz -> set("title",me->query("name")+"������������");
			rz -> set("dest_add",dest_add);
			rz -> move(room);
			if (! room2 = find_object(dest_add) )
				room2 = load_object(dest_add);
			des = "����" + to_chinese(room->query("outdoors"))+room->query("short") + "�����" + rz->query("name") + "����" + to_chinese(room2->query("outdoors")) + room2->query("short") ;
			ob = new(__DIR__"task2/miling");
			ob -> set("describe",des);
			ob -> set("src_add",room->query("short") );
			ob -> set("dest_add",room2->query("short") );
			ob -> set("src_des",room->query("outdoors") );
			ob -> set("dest_des",room2->query("outdoors") );
			ob -> move(me);
			me -> set("baobiaotime", time());
			add("count",-1);
message_vision(HIY"$NС������ش����裬������һ��ֽ��������ź�ľ�����˳��ȡ�����������С�\n"NOR,me);
			return 1;
		}
		else
		{
message_vision(YEL"$N����Ҫ�����裬һ��С�ģ�������䡯��һ�¹����������ˡ�\n"NOR,me);
			return 1;
		}
	}
	else {
message_vision(HIG"$NС������ش����裬����������ɶ��û�С�����˭�������أ����������ɡ�\n"NOR,me);
		return 1;
	}
}

void newjob()
{
	object room;
	if (query("count") <= 0) {
		if( room = find_object(__DIR__"zhonglieci") )
		message("vision",YEL"ֻ��һ���м����ɵĻ��������˽��������������ﵷ���˼��£�������ŵ����ˡ�\n"NOR,room);
		add("count",1);
	}
	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}

