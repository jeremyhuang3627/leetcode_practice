#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <tr1/unordered_set>
#include <ctime>

using namespace std;
/*
 vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        int num = L.size();
        int len = L[0].size();
        if (num==0){return res;}
        map<string,int> mp;  
        for (int i=0;i<num;i++){mp[L[i]]++;}      
          
        int i=0;
        while ((i+num*len-1)<S.size()){
            map<string,int> mp2;
            int j=0;
            while (j<num){
                string subs = S.substr(i+j*len,len);
                if (mp.find(subs)==mp.end()){
                        break;
                }else{
                    mp2[subs]++;
                    if (mp2[subs]>mp[subs]){
                        break;
                    }
                    j++;  
                }
            }
            if (j==num){res.push_back(i);}
            i++;
        }
      
        return res;
    }
*/

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> v;
    if(L.size()>0){
    int wl = L[0].length();
    int dl = L.size();
	int i=0;
	map<string,int> m;
	for(int pos=0;pos<L.size();pos++)
		m[L[pos]]++;

	    while(i < S.length())
	    {	
	    	int j = i;
	    	vector<bool> allwords (dl,false);
	    	map<string,int> m2;
	    	int c = 0;
	    	//cout << "t1 "<< endl;
	    	while(j < j + wl*dl){
	    		string ns = S.substr(j,wl);
	    		//cout << "ns " << ns << endl;
	    		//cout << "t2 "<< endl;
	    		map<string,int>::iterator it = m.find(ns);
	    		if(it!=m.end()){
	    			m2[ns]++;
	    			if(m2[ns]>1){
	    				break;
	    			}
	    			c++;
	    		}else{
	    			break;
	    		}
	    		//cout << "t3 "<< endl;
	    		j+=wl;
	    	}

	    	if(c==dl){
	    		v.push_back(i);
	    	}
	    	i ++;
	    }
    }
     return v;
} 

int main()
{
	string strArr[] = {"otftdranhdxytfnvwgkzroukdj","iflkoztdmzwdaqtpqkyuriwhef","lbsjkymmpjmtlfkuxxlghowsyz","cddjixxdtcweddevffnznpoayy","snjutchkdluooaompjooraljyp","fuszfwjukctzovbjhwnxwwkwdg","frmdfvmgfwmyqsmdxhzuwpfbjp","ukityxyfwmcctwanvdoyptfnbt","mhnneqoyuopxqhehkzotjmnbyq","vtgtjqywcowyskxonxghoytovm","wouzyhqulddiygjjkbesqyskjo","mfiasjwswrkdfdsljqwwrppfgg","zruihzkezsyrvshhbreqhkbfay","rsxpytdektctbwzroslgbmmvnl","jdwrxvlnlvwokqflrchlaywoku","xhnhoyfiqwumakqsrsfhrtzhqe","gtbdwzrehiuwmsyeykrbojqbex","tpcyljxrlsprjuttwpjxkbexds","tsjhbkkcamissiqnxrarcetpsy","keiqdjpogncrsmcjetsnnamlpw","rquqyfwksatzbpltsvnpqovlts","tdgcmxhbxtvpafvleajyikkrky","qvrmtigjzbnfknowkrwqostybg","vluaondwrptastvnivufiafsan","rnsthoepieoiklwmppkpegssgk","cyypdvniemylmrufspkbmthhvp","ihcihqcidckkxwzssuogodszzm","chrusbfcrwpyerjjhdbgsqiyhr","wmeoqwjiudnqrssizesazdhpjx","ommasyxfsyxggjchylyiqayvzy","kwntzsoikuypiridaqfyyaybbd","cwjomhuusuohhsqulihjrcuhvi","wxazcolordookgmhpvstcqgcbx","nusbgrlicgaieltynjwrhzlbml","xrtdypwgihyjdazzytkyjzxqio","xfvmmhyaqunrcdocvqjfirbiyz","fuklgcovysgodlhakwzmjnugif","hzhxvzdnpgrmimmifavnnkxgiu","xsmdvpbefqnbmhwaodueafnjpe","xfbvntylibcglmeciuzojrnesq","cnhrbilcqgyuwiukxafhgwtmoa","xkajvsfvljucnwbybsunyxjplw","zuieyhbeimbxlpzghthksugdrj","gbzqxacasrjslphkdqiidsqnik","jxtrrkucpeqfznqxmqqufbwrba","chziswmrcjifowkgitisbcruna","jyzdarflmgddwtradizletninf","pcktysrqoleirwiwsabupngajc","dkenfakvatsbkpzaqkhwpdnill","kbiooeejlfzjvrzbytxhidxkyf","wlopdvcgndqjdvtpbzoxijamac","xsoojjcpspbbvuuxpimjydikbj","faubswtonxjasbvrkznljodkbh","uqsphwxhjvjutfkpoipjecusmi","nawhcpyfhtcvukifgfskpspvry","xkdhzwfnsaljjkdnxixizikigq","zxgylunxobvrsbbzkvlxbhiddn","alltjwpccflhrdrvtgegznocdg","gffvqdfryrckdzgkjcmapzdqiu","hzedaytbveiwkpgesgphnajpzi","wmpoypwtdkcdksxzkacaeasnhb","hsdylmvlsukuljxrnnymqbsxfc","bbbncgqexyvpbnujeamneeeglj","bjhgqyvxbkrgzyouidtinttnkk","pyuxbbdmrpfzfvujldgtvypaqd","cfanwclwtouhwavunjnhogwyhl","plkgclrmcbkrwzkfkelnyeyuqd","ugvdzbpgvtsapxwlkzbvopmxon","msbmzaftkpvutwotnklutnnydx","pdwgwqysgwyehsfcsitfbmdrdt","elgaomtrrqtiucspyfhxjijajx","biqyonpgpihdnpbcpbohuvmfkh","llmhulbiqwzscfiqiuxgwomqsm","mpucnjxscajcqtfptaujwtrgui","gdzsnldtlmdwgtxzewvcpxzgqq","gdtdkhktidcgxyxhdcmyqwqosj","zubitucqjalnevigrmeqfuiqbl","aymdqsspjtjtwbomtameefzctp","kjezjhjsqbslzuvqcvrrrzwkjk","zavglghtuyzbhlgjwcawdardhc","fawzisqdrqkjkvnodlwowgrbyh","vrzjxyvnnykpgxuxixucpvddum","rdutdqevagpsjduvxgarhefihk","ydhiysnlehnrsnwjsloropxeea","hgjoksiqqtcohwirqvdpmsfmev","jyxuwgzpxotdcqnerzteyvwwse","sozxjhzgfjrcalpejaazyizodi","usobvjohdklmuqyogoquaigqwx","tmdhnkgfttasmpuqpyjxbzcnir","quareyrcczjfqvkebtpmnyjwmk","rmwwnugsdhokxikirtuxjtfibg","qsrqplxkqwlgfibxjquheggfdx","rukzgcdcxguddvlsnuxjrxrroz","oomuuzvkjkadkkhjlpjtittewo","wqwmfoewfujegzcuhhclenbbxf","yjogxeizuxbaghfeirprcienbt","qbwoapykiypvpuepswsybkcwzs","lvtfogfmqhcqpjlrgidopjwiun","rwowsvphzuelckjrkbjwejdgdb","jfqppedmvkczjmnzcpwxiebofu","hygatxfrdchcuoysshlzlfifml","gxqhkvxtmabaetgcnfkjpjjurr","zppdswzkweihasjtuzoxjywwvs","hgyikgtrellftwupqldsinlzfw","kckkuanjaeodnfzbzdqpdypgmo","aiijvcapujmrrxocshhexxnmgr","sjiryclpfjywsdgdpctpqzdivg","kuxyveeffzlpkopbevsahdskve","uqvhzoyosogeuwhpdqzvipaofj","gjhxstzhjpwtoocxirprjfmqwm","cwiflosufdxikbaejqthzgzcqe","qeqqaevctxasmlgnpjrwvootdj","ymggqqmcyargmnbbqpnveahhud","ekomqxpmaatkvbpxhnyhwdljdb","zvamtphntngeyjnytrmorbxnuf","uhoynppfujdvwzaghcbsyxsoub","efhbteijbapnfpwkkqcslwjram","koxmouvdckchsufmghyyarqhyh","tthudiuudavkeljdwkdtopindj","nwwbpbxzvqvohylllztyaboska","dccrgppcsfgrgbhcsrcfcngynh","qdpakrphkeixdwuibmjxlbzwdd","ftgsfqdmrttgfbwgtzdbdnijme","ounppmwshjlgxtjzzumgzwcyml","cpvqmbnzovdcqbwzsbkbcvydjh","pbrjsfehxtttldfwlcsudrqpzp","qbcnnbgheeyakihitnltmlmyjw","ztvabkcldvosfcbbbuxzcajzpt","xfpwpemdygftsqgttqfcbtrlmb","hncqzkvackmgexujtbcqcipxmg","ilfaognmgqysbvfbjhextbkhhd","hvqwunsdsydtqfanjmiwujpxua","yqrkmrvaasgktchwdoekuobjff","egeeotdsaixdikuodytbxasmwx","jfmncifbumpbiuxtadudxekcpr","slozeilagywptbwhmvqwdjszgb","kkugasdoirfyucgqpfuznudzjv","pvapxxizhhxeukcebjdvimucqj","bqurcvltquzjcwzkzqyletteqf","cbrsrxlthlcobgwkhyqzwlubyf","mqzhitoyteqklmwoisqkaxmbpk","nbnapfbgovoucnnygadnzqrrkv","ztpvheqivqfdpokosgyxkbipws","auvgoeglyctzrspmvrcjyuirai","yhmloltnczhrnkqcqgzayuquxu","funvzsxwvpsrdhqokjpfcceqnq","vuhfgazqzhuejtlgyqdllsfiew","gmhucjdtfwwmanjpopjxasceyv","vpscszndfymaamqrhelnvleejx","dzseaqbaqfqdvhjjvtqkbhhtaj","zylxwmidkjrprjjtgxwnideifj","nzohposakdwbgagtkxwbtrjzxk","igvivhesfcwlhdnstxhkblhtnp","trncoqmgqatfjkpqnffqjutxen","vwfgyohathrbsdhxjfsaivkjiq","rdnudjqlftvznzbklgxvlthqmv","kopvaawtlitzukijdtqppnoavy","raldklntxlxzarimkzkyceglkf","nakocmxbxpxjicushiotpxnxro","wxoqmpobugtnxeiizelnqeofjs","smsvftlyfxqazquiankjkpxozu","fwksrutpcuelminzgnriklqzlc","nefzowdhswsxcbdmdfvilekzcr","ibvibngseakyaqaxuipalllsor","znvyamllvnymacnmvllfqymdlk","gcvyilxrrlewkwowgapvjruwub","mwehdfbalretcfxxeppwdnniwn","wwoahxbovwqalhgcworiwyitlx","nmxpfoezilnocxsrfcebqtsdkw","engqldbfdrugonxjnqckfkfcro","grckaheoegibceqwvvdljnwyuz","jcbpbfahfrvyimodwjgpyewhdf","rvflwimnafknauacickeoteeuc","gxygwzbrzddbohzcbgheiiyhhc","wcxgwradmfsmhzkguwsjhtlizb","bikoixpunrhlsgcsrlwmdfusyl","ssetdnybhxzsmkpkybbgosiwgi","vyehhabqjcbtgdiovawlqtfqmh","opmumwbogkhjukleukcufuqvce","vjriasqbobmskfsbdmydejkagm","gjlgkhsaxqrvmufoyrjxqvztxd","yyybihdpkfnghlkrhvhnzbwqkj","kznoomkzsiitpqhqquhraqkkbc","yhztklllvwhjuapmnazjrhbhrb","jjiormhgckcqsswnmcfrhgcqoo","rphbmsfnhguhpzakalyoowzunz","igmgonijvtpdokdnlmatvzxyvd","rsqptcgixgkvbxgxwcjglpzbeq","zldspjxugpxlgydliikouvsgyj","enzqysidqtopmajbrvwmoudxrp","naktraokohuwstyibkvpihgeyx","zlfxzldfstaxmcflfpybdbzzew","mfzoayxolozeddfkxswnuovwow","rodrvuobikjwxlckyeeyjoctus","yfbwljegrzpysxaqihwxzrxiby","croqduliogssfqdfalhglmtbrj","gvfrtkexyjzigcdydnqfpgrxeg","xgwrgupmdxoepxistovdeqfdcv","oxggnlexqqmkktpjbzkbfwtydt","pyopssuxecxbfqgdwjgaglgtmv","svqwsfwoczrhmiztjgqfqcjyve","bartebhenxylaavcjnwobeycdy"};
	vector<string> l;
	for(int i=0;i<sizeof(strArr)/sizeof(strArr[0]);i++)
	{
		l.push_back(strArr[i]);
	}

	string s = "cxksvbkmmlkwviteqccjhsedjmoyimskmeehhovubiszsodiqhtyaxdlktmuiggukldubzqdjiebyjkpqfpqdsepmqluwrqictcguslddphdyrsowjhbcnsqddmbvclzvqhsksxnhethvnyuxfxzsqpxvdasflscbzumssbbwuluijqhqngkfxhdahvhunjwpgkjylmwixssgizyyhifepigyenttyriebtcogbwftqmcpmcwvhcmsklyxgryxccyvhodiljbbxftjhrerurleejekacheehclvfviqxmnefzowdhswsxcbdmdfvilekzcrukityxyfwmcctwanvdoyptfnbtrnsthoepieoiklwmppkpegssgknmxpfoezilnocxsrfcebqtsdkwjfqppedmvkczjmnzcpwxiebofujyxuwgzpxotdcqnerzteyvwwseauvgoeglyctzrspmvrcjyuiraimwehdfbalretcfxxeppwdnniwnegeeotdsaixdikuodytbxasmwxzlfxzldfstaxmcflfpybdbzzewzylxwmidkjrprjjtgxwnideifjkeiqdjpogncrsmcjetsnnamlpwotftdranhdxytfnvwgkzroukdjmpucnjxscajcqtfptaujwtrguiwouzyhqulddiygjjkbesqyskjofawzisqdrqkjkvnodlwowgrbyhzruihzkezsyrvshhbreqhkbfaymsbmzaftkpvutwotnklutnnydxihcihqcidckkxwzssuogodszzmopmumwbogkhjukleukcufuqvcezxgylunxobvrsbbzkvlxbhiddnzuieyhbeimbxlpzghthksugdrjkznoomkzsiitpqhqquhraqkkbcgjhxstzhjpwtoocxirprjfmqwmhgyikgtrellftwupqldsinlzfwfrmdfvmgfwmyqsmdxhzuwpfbjprwowsvphzuelckjrkbjwejdgdbxkdhzwfnsaljjkdnxixizikigqrmwwnugsdhokxikirtuxjtfibgslozeilagywptbwhmvqwdjszgbsnjutchkdluooaompjooraljypusobvjohdklmuqyogoquaigqwxsjiryclpfjywsdgdpctpqzdivgqbwoapykiypvpuepswsybkcwzsxfbvntylibcglmeciuzojrnesqounppmwshjlgxtjzzumgzwcymlpbrjsfehxtttldfwlcsudrqpzpnbnapfbgovoucnnygadnzqrrkvkckkuanjaeodnfzbzdqpdypgmoydhiysnlehnrsnwjsloropxeeacwjomhuusuohhsqulihjrcuhvixsmdvpbefqnbmhwaodueafnjpellmhulbiqwzscfiqiuxgwomqsmxfvmmhyaqunrcdocvqjfirbiyzwmpoypwtdkcdksxzkacaeasnhbgjlgkhsaxqrvmufoyrjxqvztxdvpscszndfymaamqrhelnvleejxbiqyonpgpihdnpbcpbohuvmfkhtrncoqmgqatfjkpqnffqjutxenuqvhzoyosogeuwhpdqzvipaofjkbiooeejlfzjvrzbytxhidxkyfzavglghtuyzbhlgjwcawdardhcigmgonijvtpdokdnlmatvzxyvdymggqqmcyargmnbbqpnveahhudgtbdwzrehiuwmsyeykrbojqbexelgaomtrrqtiucspyfhxjijajxjcbpbfahfrvyimodwjgpyewhdfrphbmsfnhguhpzakalyoowzunzbjhgqyvxbkrgzyouidtinttnkkkjezjhjsqbslzuvqcvrrrzwkjkgdzsnldtlmdwgtxzewvcpxzgqqhncqzkvackmgexujtbcqcipxmgwlopdvcgndqjdvtpbzoxijamacvrzjxyvnnykpgxuxixucpvddumpvapxxizhhxeukcebjdvimucqjztpvheqivqfdpokosgyxkbipwsbqurcvltquzjcwzkzqyletteqffaubswtonxjasbvrkznljodkbhfunvzsxwvpsrdhqokjpfcceqnqgrckaheoegibceqwvvdljnwyuzcbrsrxlthlcobgwkhyqzwlubyfrvflwimnafknauacickeoteeucrodrvuobikjwxlckyeeyjoctusnawhcpyfhtcvukifgfskpspvrylvtfogfmqhcqpjlrgidopjwiunalltjwpccflhrdrvtgegznocdgnzohposakdwbgagtkxwbtrjzxkoomuuzvkjkadkkhjlpjtittewoxfpwpemdygftsqgttqfcbtrlmbefhbteijbapnfpwkkqcslwjramkuxyveeffzlpkopbevsahdskveigvivhesfcwlhdnstxhkblhtnpyfbwljegrzpysxaqihwxzrxibyvjriasqbobmskfsbdmydejkagmrdutdqevagpsjduvxgarhefihkrukzgcdcxguddvlsnuxjrxrrozvuhfgazqzhuejtlgyqdllsfiewhvqwunsdsydtqfanjmiwujpxuapcktysrqoleirwiwsabupngajcjyzdarflmgddwtradizletninfvwfgyohathrbsdhxjfsaivkjiqcyypdvniemylmrufspkbmthhvpcfanwclwtouhwavunjnhogwyhluqsphwxhjvjutfkpoipjecusmiaiijvcapujmrrxocshhexxnmgrraldklntxlxzarimkzkyceglkfjxtrrkucpeqfznqxmqqufbwrbaxhnhoyfiqwumakqsrsfhrtzhqekoxmouvdckchsufmghyyarqhyhbartebhenxylaavcjnwobeycdytthudiuudavkeljdwkdtopindjrdnudjqlftvznzbklgxvlthqmvfuklgcovysgodlhakwzmjnugifcpvqmbnzovdcqbwzsbkbcvydjhqdpakrphkeixdwuibmjxlbzwddtdgcmxhbxtvpafvleajyikkrkyvluaondwrptastvnivufiafsanengqldbfdrugonxjnqckfkfcrocwiflosufdxikbaejqthzgzcqeoxggnlexqqmkktpjbzkbfwtydtgcvyilxrrlewkwowgapvjruwubsozxjhzgfjrcalpejaazyizodihzedaytbveiwkpgesgphnajpziyyybihdpkfnghlkrhvhnzbwqkjquareyrcczjfqvkebtpmnyjwmkxkajvsfvljucnwbybsunyxjplwnusbgrlicgaieltynjwrhzlbmlzvamtphntngeyjnytrmorbxnufmfiasjwswrkdfdsljqwwrppfgggdtdkhktidcgxyxhdcmyqwqosjekomqxpmaatkvbpxhnyhwdljdbfuszfwjukctzovbjhwnxwwkwdgzppdswzkweihasjtuzoxjywwvsuhoynppfujdvwzaghcbsyxsoubmqzhitoyteqklmwoisqkaxmbpkyhztklllvwhjuapmnazjrhbhrbgffvqdfryrckdzgkjcmapzdqiuzldspjxugpxlgydliikouvsgyjgbzqxacasrjslphkdqiidsqniklbsjkymmpjmtlfkuxxlghowsyzkopvaawtlitzukijdtqppnoavyrsqptcgixgkvbxgxwcjglpzbeqqvrmtigjzbnfknowkrwqostybgnaktraokohuwstyibkvpihgeyxztvabkcldvosfcbbbuxzcajzptgxygwzbrzddbohzcbgheiiyhhchsdylmvlsukuljxrnnymqbsxfchgjoksiqqtcohwirqvdpmsfmevpyuxbbdmrpfzfvujldgtvypaqdsvqwsfwoczrhmiztjgqfqcjyvewmeoqwjiudnqrssizesazdhpjxrsxpytdektctbwzroslgbmmvnlzubitucqjalnevigrmeqfuiqblcnhrbilcqgyuwiukxafhgwtmoagxqhkvxtmabaetgcnfkjpjjurrtmdhnkgfttasmpuqpyjxbzcnirxsoojjcpspbbvuuxpimjydikbjjdwrxvlnlvwokqflrchlaywokussetdnybhxzsmkpkybbgosiwgiwcxgwradmfsmhzkguwsjhtlizbchziswmrcjifowkgitisbcrunanakocmxbxpxjicushiotpxnxrobikoixpunrhlsgcsrlwmdfusylplkgclrmcbkrwzkfkelnyeyuqdznvyamllvnymacnmvllfqymdlkilfaognmgqysbvfbjhextbkhhdftgsfqdmrttgfbwgtzdbdnijmekwntzsoikuypiridaqfyyaybbdommasyxfsyxggjchylyiqayvzywxazcolordookgmhpvstcqgcbxdzseaqbaqfqdvhjjvtqkbhhtajmhnneqoyuopxqhehkzotjmnbyqiflkoztdmzwdaqtpqkyuriwhefvtgtjqywcowyskxonxghoytovmxrtdypwgihyjdazzytkyjzxqioqbcnnbgheeyakihitnltmlmyjwyjogxeizuxbaghfeirprcienbtyqrkmrvaasgktchwdoekuobjffsmsvftlyfxqazquiankjkpxozucddjixxdtcweddevffnznpoayypyopssuxecxbfqgdwjgaglgtmvibvibngseakyaqaxuipalllsorfwksrutpcuelminzgnriklqzlcnwwbpbxzvqvohylllztyaboskadccrgppcsfgrgbhcsrcfcngynhbbbncgqexyvpbnujeamneeegljtsjhbkkcamissiqnxrarcetpsyvyehhabqjcbtgdiovawlqtfqmhxgwrgupmdxoepxistovdeqfdcvyhmloltnczhrnkqcqgzayuquxumfzoayxolozeddfkxswnuovwowqeqqaevctxasmlgnpjrwvootdjhzhxvzdnpgrmimmifavnnkxgiuwwoahxbovwqalhgcworiwyitlxdkenfakvatsbkpzaqkhwpdnillgvfrtkexyjzigcdydnqfpgrxegcroqduliogssfqdfalhglmtbrjjjiormhgckcqsswnmcfrhgcqoochrusbfcrwpyerjjhdbgsqiyhrgmhucjdtfwwmanjpopjxasceyvugvdzbpgvtsapxwlkzbvopmxonqsrqplxkqwlgfibxjquheggfdxwqwmfoewfujegzcuhhclenbbxfjfmncifbumpbiuxtadudxekcprrquqyfwksatzbpltsvnpqovltspdwgwqysgwyehsfcsitfbmdrdthygatxfrdchcuoysshlzlfifmltpcyljxrlsprjuttwpjxkbexdsenzqysidqtopmajbrvwmoudxrpaymdqsspjtjtwbomtameefzctpwxoqmpobugtnxeiizelnqeofjskkugasdoirfyucgqpfuznudzjvfxaqrnbntdiyrqrzrmbxcsdyrsuwterzdurxjskcvscpltqchrbjlgkczgyumrtqlnnufzyduauhwklddmpotbsuhsoulkmxxbtcauhwwbdsnqysdniyoasvugrgqdfneashubftdjnsblneyvcoyumsddatjhjnidueeaxjllemyrtxmxnkszfxfhqopbbxeydladunoybopwlcubooavlfddvsfxrlxuwzxrmnrpchmpliqbwtxhyckuuptldshzrfsfukwwtiogqehoxgvyigucxppahzcygwfaibzbmnjetrttzoriwnmucewldaljxqjfrkjdxsitldmlrfvoshkwnghqhszgilnbvwhvrroeuaplhmbzulxhueabybjimwjkvqhmjvqdxireuufqgcaaiadgbmoqkzafshtbemhduahquohasjcajfimryccxejpndtrpcwlcdbwtkzltbnchxpavtevyqmltffkjbvlhwkajjocmdhvbywyrctpsidnpixzlsksrwvaflcuojprhlqbqlqivtwldtkpowjftefaphugtkxcxpdndwyyrujvpvmdsxklcpntzibusbwpqcdvybupxfmobautyegcwtxvbzpvanlspqoptkhspviswclwjtafnxcqytmaiztarjpmtygkuodstqockqjznnpmgdmqehqxqgjlgrwagbuzrkdbaocobscjxqzeyqbqynegechmddnuosyogaejuiuuzuyzmzrmovutxbfchvzvnzjuzqfwyaqxwqykrqygnsznwgpddoyrnjnpzsnysdxqvyamqysdttqpcgsfwswkbjzdemdyrcpoaraqstulomcquuwroudrgcumqzkjcbxctzvlsryhdazawxrksubayy";

	clock_t start;
	double duration;
	start = clock();
	vector<int> v = findSubstring(s,l);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"time used: "<< duration <<'\n';

	for(int i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}